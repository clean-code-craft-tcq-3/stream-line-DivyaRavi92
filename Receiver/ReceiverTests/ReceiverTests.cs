using System.Collections.Generic;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using Receivers;
namespace ReceiverTests
{
  [TestClass]
  public class ReceiverTests
  {
    [TestMethod("Method to test the if the input string is split correctly.")]
    public void SplitInputStringTestMethod()
    {
      string input = "Temperature Array\n" +
                     "- 1 ,49 ,43 ,1 ,39 ,18 ,47 ,46 ,\n" +
                     "SOC Array\n" +
                     "51 ,54 ,48 ,60 ,67 ,54 ,48 ,67 ,57, \n ";

      string[] splitInput = Receiver.SplitInputString(input);

      Assert.AreEqual(splitInput[0], "Temperature Array");

      Assert.AreEqual(splitInput[1], "- 1 ,49 ,43 ,1 ,39 ,18 ,47 ,46 ,");

      Assert.AreEqual(splitInput[2], "SOC Array");

      Assert.AreEqual(splitInput[3], "51 ,54 ,48 ,60 ,67 ,54 ,48 ,67 ,57, ");
    }

    [TestMethod("Method to convert csv to the sensorReading")]
    public void ConvertToSensorReading()
    {
      string csvInput = "-1, 49, 43, 1, 39, 18, 47, 46, ";

      List<int> sensorReading = Receiver.ConvertCsvToSensorReading(csvInput);

      
     CollectionAssert.AreEqual(sensorReading, new List<int> {-1 ,49 ,43, 1, 39, 18, 47, 46});
    }

    [TestMethod("Method to get the max value in the given list")]
    public void GetMaxValueTestMethod()
    {
      List<int> inputList = new List<int> { -1, 10, 13, 12, 22, 21 };

      int maxValue = Receiver.GetMaximumValue(inputList);

      Assert.AreEqual(maxValue, 22);
    }

    [TestMethod("Method to get the min value in the given list")]
    public void GetMinValueTestMethod()
    {
      List<int> inputList = new List<int> { -1, 10, 13, 12, 22, 21 };

      int minValue = Receiver.GetMinimumValue(inputList);

      Assert.AreEqual(minValue, -1);
    }

    [TestMethod("Method to get the sample average value in the given list")]
    public void GetSampleAverageTestMethod()
    {
      List<int> inputList = new List<int> { 1,2,3,4,5 };

      int sampleAverage = Receiver.GetSimpleMovingAverage(inputList);

      Assert.AreEqual(sampleAverage, 3);
    }

    [TestMethod("Method to test the Get Statistics method")]
    public void GetStatisticsTestMethod()
    {
      List<int> temperatureList = new List<int>() { 1, 2, 3, 4, 5 };
      List<int> socList = new List<int>() { 21, 31, 45, 68, 80 };

      string statistics = Receiver.GetStatistics(temperatureList, socList);

      string title = "------------------  Statistics  ------------------\n";
      string temperatureStatistics = "Maximum Temperature: 5" + "\n" +
                                     "Minimum Temperature: 1" + "\n" +
                                     "SimpleMovingAverage: 3" +
                                     "\n\n";

      string stateOfChargeStatistics = "Maximum StateOfCharge: 80" +
                                       "\n" +
                                       "Minimum StateOfCharge: 21" +
                                       "\n" +
                                       "SimpleMovingAverage: 49" +
                                       "\n";

      string endOfLine = "-----------------------------------------------------";

      string printLine = title + temperatureStatistics + stateOfChargeStatistics + endOfLine;

      Assert.AreEqual(statistics, printLine);
    }
    
    [TestMethod("Method to test GetTemperature method")]
    public void GetTemperatureTestMethod()
    {
      string value = "1,2,3,4,5";

      List<int> temperatureList = Receiver.GetTemperatureList(value);

      CollectionAssert.AreEqual(temperatureList, new List<int>(){1,2,3,4,5});
    }

    [TestMethod("Method to test GetTemperature method")]
    public void GetSocTestMethod()
    {
      string value = "10,20,30,40,50";

      List<int> temperatureList = Receiver.GetSocList(value);

      CollectionAssert.AreEqual(temperatureList, new List<int>() { 10, 20, 30, 40, 50 });
    }
  }
}
