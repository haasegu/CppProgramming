    // Vorlesung 17.3.2023
    #include <iostream>
    #include <string>
    using namespace std;
    
    /** Ausgabe eines Strings zur Feinstaubanalyse
    *  @param[in] mg  Feinstaub in Mikrogramm
    */
    void feinstaub(const double mg)
    {
        string ss;
        if (mg >= 50) {
            ss = " zu viel";
        } else if (mg>=10) {
            ss =  " es geht";
        } else if (mg>=0) {
            ss =   " es geht";
        } else {
            ss =  " Fehler";
        }
    
        cout << ss << endl;
    
        return;
    }
    
    /** Einlesen einer ganze Zahl solange, bis diese Zahl aus
    *   dem Intervall [a,b] ist.
    *  @param[in]  a  Intervallanfang
    *  @param[in]  b  Intervallende
    *  @return ganze Zahl aus [a,b]
    *  @warning implizite Bedingung @f$ a \le b @f$ wird nicht ueberprueft
    *  @warning Keine Absicherung bzgl. Fehleingaben
    */
    int eingabe(const int a, const int b)
    {
        int k;
        do {
            cout << " Gib Zahl aus [" << a << "," << b << "] ein : ";
            cin >> k;
        } while ( !( a<=k && k<=b ) );
    
        return k;
    }
    
    /** Summation ungeraden natuerlichen Zahlen @f$ \le n @f$ uber einen Zaehlzyklus
    *   (ausfuehrliche Version).
    *  @param[in]  n  letzte ungerade Zahl ist nicht groesser als n
    *  @return Resultat @f$ \sum\limits_{k=1, {ungerade}}^n  k @f$
    *  @warning Keine Absicherung bzgl. Zahlbereichsuberschreitung
    */
    int summe_for(const int n)
    {
        int sum = 0;
        for (int k=1; k<=n; k=k+2) {
            sum = sum +k;
        }
        return sum;
    }
    
    /** Summation ungeraden natuerlichen Zahlen @f$ \le n @f$ uber einen Zaehlzyklus
    *   (Version mit zusammengezogenen Operatoren).
    *  @param[in]  n  letzte ungerade Zahl ist nicht groesser als n
    *  @return Resultat @f$ \sum\limits_{k=1, {ungerade}}^n  k @f$
    *  @warning Keine Absicherung bzgl. Zahlbereichsuberschreitung
    */
    int summe_for2(const int n)
    {
        int sum = 0;
        for (int k=1; k<=n; k+=2) {
            sum += k;
        }
        return sum;
    }
    
    /** Summation ungeraden natuerlichen Zahlen @f$ \le n @f$ uber einen Zaehlzyklus
    *   (stark zusammengezogene Version, nicht empfehlenswert).
    *  @param[in]  n  letzte ungerade Zahl ist nicht groesser als n
    *  @return Resultat @f$ \sum\limits_{k=1, {ungerade}}^n  k @f$
    *  @warning Keine Absicherung bzgl. Zahlbereichsuberschreitung
    */
    int summe_for3(const int n)
    {
        int sum(0) ;
        // Bitte nicht so !!
        for (int k=1 ; k<=n; sum+=k, k+=2)  { }
        return sum;
    }
    
    /** Summation ungeraden natuerlichen Zahlen @f$ \le n @f$ uber abweisenden Zyklus.
    *  @param[in]  n  letzte ungerade Zahl ist nicht groesser als n
    *  @return Resultat @f$ \sum\limits_{k=1, {ungerade}}^n  k @f$
    *  @warning Keine Absicherung bzgl. Zahlbereichsuberschreitung
    */
    int summe_while(const int n)
    {
        int sum(0), k(1);
        while (k<=n) {
            sum += k;
            ++k;
            ++k;
        }
        return sum;
    }
    
    
    int main()
    {
        double fmg;
        cout << " Konzentration: ";
        cin >> fmg;
        feinstaub(fmg);
    
        int as = eingabe(1,20);
        cout << "Zahl: " << as << endl;
    
        int sum = summe_for(as);
        cout << " Summe = " << sum << endl;
        sum = summe_while(as);
        cout << " Summe = " << sum << endl;
    
        cout << "Hello world!" << endl;
        return 0;
    }
    
