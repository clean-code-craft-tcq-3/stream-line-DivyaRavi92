using System;
using System.Collections.Generic;
using System.Diagnostics.CodeAnalysis;
using System.Linq;

namespace Receivers
{
  public class Receiver
  {
    [ExcludeFromCodeCoverage]
    static void Main()
    {
      string inputReading = Console.In.ReadToEnd();

      Console.WriteLine(inputReading);

      string[] formattedInputString = SplitInputString(inputReading);

      List<int> temperatureList = GetTemperatureList(formattedInputString[1]);

      List<int> socList = GetSocList(formattedInputString[3]);

      string statistics = GetStatistics(temperatureList, socList);

      DisplayOnConsole(statistics);
    }

    private static List<int> GetTemperatureList(string inputArray)
    {
      List<int> temperatureList = ConvertCsvToSensorReading(inputArray);

      return temperatureList;
    }

    private static List<int> GetSocList(string inputArray)
    {
      List<int> socList = ConvertCsvToSensorReading(inputArray);

      return socList;
    }


    public static List<int> ConvertCsvToSensorReading(string csvInput)
    {
      string[] inputArray = csvInput.Split(",");
      int number = 0;

      List<int> list = (from input in inputArray where int.TryParse(input, out number) select number).ToList();

      return list;
    }

    public static string[] SplitInputString(string consoleOutput)
    {
      return consoleOutput.Split(new[] { "\n" }, StringSplitOptions.None);
    }

    public static int GetMaximumValue(List<int> inputList)
    {
      int maximumValue = inputList.Max();

      return maximumValue;
    }

    public static int GetMinimumValue(List<int> inputList)
    {
      int minimumValue = inputList.Min();

      return minimumValue;
    }

    public static int GetSimpleMovingAverage(List<int> inputList)
    {
      int sumOfInputReadings = inputList.Sum();
      int countOfInputValues = inputList.Count;

      return sumOfInputReadings / countOfInputValues;
    }

    private static string GetStatistics(List<int> temperatureList, List<int> socList)
    {
      string title = "------------------  Statistics  ------------------\n";
      string temperatureStatistics = $"Maximum Temperature: {GetMaximumValue(temperatureList)}" + "\n" +
                                     $"Minimum Temperature: {GetMinimumValue(temperatureList)}" + "\n" +
                                     $"SimpleMovingAverage: {GetSimpleMovingAverage(temperatureList)}" +
                                     "\n\n";

      string stateOfChargeStatistics = $"Maximum StateOfCharge: {GetMaximumValue(socList)}" +
                                       "\n" +
                                       $"Minimum StateOfCharge: {GetMinimumValue(socList)}" +
                                       "\n" +
                                       $"SimpleMovingAverage: {GetSimpleMovingAverage(socList)}" +
                                       "\n";

      string endOfLine = "-----------------------------------------------------";

      return title + temperatureStatistics + stateOfChargeStatistics + endOfLine;
    }

    private static void DisplayOnConsole(string displayMessage)
    {
      Console.WriteLine(displayMessage);
    }
  }
}
