#include <iostream>
#include <vector>                //  vector
#include <cassert>
using namespace std;


/** \brief Berechnung von Folgengliedern
 *         entsprechend der Formel
 *         @f$ x_n = \frac{1}{n} \sum\limits_{k=1}^{n} \frac{2k+1}{2n+1} \qquad\forall n=1,\ldots,nsize @f$.
 *
 * \param[in] nsize  Anzahl der zu berechnenden Glieder
 * \return Vektor der Folgenglieder
 *
 */
vector<double> folge(const int nsize)
{
    vector<double> x(nsize);

    for (int n=1; n<=x.size(); ++n)
    {
        double tmp =0.0;             // nur innerhalb des n-Loops gueltig
        for (int k=1; k<=n; ++k)
        {
            tmp += (2*k+1.0)/(2*n+1);
        }
        x[n-1] = tmp/n;                // Indizierung von 0 bis (nsize-1)
    }
    return x;
}

/** \brief Berechnung von Folgengliedern
 *         entsprechend der Formel
 *         @f$ x_n = \frac{1}{n} \sum\limits_{k=1}^{n} \frac{2k+1}{2n+1} \qquad\forall n=1,\ldots,nsize @f$.
 *
 *         Es wird push_back() zur dynamischen Verlängerung des Vektors benutzt.
 *
 * \param[in] nsize  Anzahl der zu berechnenden Glieder
 * \return Vektor der Folgenglieder
 *
 */
vector<double> folge_dynamisch(const int nsize)
{
    vector<double> x;                // Laenge 0

    for (int n=1; n<=nsize; ++n)     // n i c h t    n<=x.size() !!
    {
        double tmp =0.0;             // nur innerhalb des n-Loops gueltig
        for (int k=1; k<=n; ++k)
        {
            tmp += (2*k+1.0)/(2*n+1);
        }
        x.push_back(tmp/n);                // Indizierung von 0 bis (nsize-1)
    }
    return x;
}

/** \brief Berechnung von Folgengliedern
 *         entsprechend der Formel
 *         @f$ x_n = \frac{1}{n} \sum\limits_{k=1}^{n} \frac{2k+1}{2n+1} \qquad\forall n=1,\ldots,nsize @f$.
 *
 *         Es wird push_back() zur dynamischen Verlängerung des Vektors benutzt.
 *
 * \param[in] nsize  Anzahl der zu berechnenden Glieder
 * \param[out] x     Vektor der Folgenglieder
 *
 */
void folge_d2(const int nsize, vector<double> &x)
{
    x.clear();

    for (int n=1; n<=nsize; ++n)     // n i c h t    n<=x.size() !!
    {
        double tmp =0.0;             // nur innerhalb des n-Loops gueltig
        for (int k=1; k<=n; ++k)
        {
            tmp += (2*k+1.0)/(2*n+1);
        }
        x.push_back(tmp/n);                // Indizierung von 0 bis (nsize-1)
    }
    return;
}

int main()
{
    cout << "Hello world!" << endl;

    int nn;
    cout << "nsize = "; cin >> nn;

    vector<double> a = folge(nn);
    cout << "letzes Element: " << a.back();
    cout << "   diff: " << a.back()-(nn+2.0)/(2*nn+1.0) << endl;

    vector<double> b(2);
    folge_d2(nn,b);
    cout << "letzes Element: " << b.back();
    cout << "   diff: " << b.back()-(nn+2.0)/(2*nn+1.0) << endl;
    cout << " Laenge von  " << b.size() << endl;

    return 0;
}
