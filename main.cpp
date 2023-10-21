#include "polynomian.h"
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

class LagrangeInterpolator
{
public:
    // Konstruktor przyjmuje dwie listy: x (punkty wej�ciowe) i y (warto�ci funkcji w tych punktach).
    LagrangeInterpolator(const vector<double>& x, const vector<double>& y)
        : x_values(x), y_values(y)
{
    }

    // Funkcja obliczaj�ca warto�� wielomianu Lagrange'a w danym punkcie 'x_interp'.
    double interpolate(double x_interp)
  {
        double result = 0;
        for (size_t i = 0; i < x_values.size(); ++i)
        {
            double term = y_values[i];
            for (size_t j = 0; j < x_values.size(); ++j)
            {
                if (i != j) {
                    term *= (x_interp - x_values[j]) / (x_values[i] - x_values[j]);
                }
            }
            result += term;
        }
        return result;
    }

private:
    vector<double> x_values;
    vector<double> y_values;
};

int main()
{
  cout << "�eby zako�czy� wpisywanie wielomianu wpisz end " <<endl;
  cout << " " <<endl;
  vector<vector<double>> polynomials; // Przechowuje wsp�czynniki   wielomian�w
  vector<int> degrees; // Przechowuje stopnie wielomian�w

  for (int i = 1; i <= 2; i++)
  {
    cout << "Podaj wsp�czynniki " << i
         << " wielomianu, zaczynaj�c od najwy�szej pot�gi:" << endl;
    vector<double> poly;
    double coefficient;

    while (cin >> coefficient)
    {
      if (cin.fail())
      {
        string input;
        cin.clear();
        cin >> input;
        if (input == "end")
        {
          break; // Zako�cz wczytywanie po wpisaniu "end"
        }
        else
        {
          cout << "B��d! Wprowad� prawid�ow� liczb� lub 'end'." << endl;
        }
      }
      else
      {
        poly.push_back(coefficient);
      }
    }

    int degree = Polynomian::Degree(poly);
    cout << "Stopie� wielomianu " << i << ": " << degree << endl;
    cout.flush(); // Wymuszenie wy�wietlenia wyniku

    polynomials.push_back(poly);
    degrees.push_back(degree);

    // Wyczy�� bufor wej�cia cin, aby umo�liwi� wprowadzenie wsp�czynnik�w dla
    // drugiego wielomianu
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
  }

  vector<double> sum = Polynomian::Add(polynomials[0], polynomials[1]);
  cout << "Wynik dodawania: ";
  for (double coef : sum)
  {
    cout << coef << " ";
  }
  cout << endl;

  vector<double> difference =
      Polynomian::Subtract(polynomials[0], polynomials[1]);
  cout << "Wynik odejmowania: ";
  for (double coef : difference)
  {
    cout << coef << " ";
  }
  cout << endl;

  vector<double> product = Polynomian::Multiply(polynomials[0], polynomials[1]);
  cout << "Wynik mno�enia: ";
  for (double coef : product)
  {
    cout << coef << " ";
  }
  cout << endl;

  // Interpolacja wielomianowa Lagrange'a dla sumy wielomian�w poly1 i poly2
  vector<double> x_values;
  vector<double> y_values;

  int num_points;
  cout << "Podaj liczb� punkt�w: ";
  cin >> num_points;

  for (int i = 0; i < num_points; ++i)
  {
      double x, y;
      cout << "Podaj punkt " << i + 1 << " (x y): ";
      cin >> x >> y;
      x_values.push_back(x);
      y_values.push_back(y);
  }

  LagrangeInterpolator interpolator(x_values, y_values);

  double x_interp;
  cout << "Podaj punkt do interpolacji: ";
  cin >> x_interp;

  double interpolated_value = interpolator.interpolate(x_interp);

  cout << "Interpolowana warto�� dla x = " << x_interp << " to " << interpolated_value << endl;

  return 0;
  }
