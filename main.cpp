#include "Header.h"


int main() {
    const int numClasses = 4;
    SocialClass** society = new SocialClass * [numClasses];
    int x;
    int Tpopulation = 0;
    cout << "Enter no. of Peasent: ";
    cin >> x;
    x = abs(x);
    Tpopulation += x;
    society[0] = new Peasant(x);
    cout << "Enter no. of Merchant: ";
    cin >> x;
    x = abs(x);
    Tpopulation += x;
    society[1] = new Merchant(x);
    cout << "Enter no. of Noble: ";
    cin >> x;
    x = abs(x);
    Tpopulation += x;
    society[2] = new Noble(x);
    cout << "Enter no. of Military: ";
    cin >> x;
    x = abs(x);
    Tpopulation += x;
    society[3] = new Military(x);

    // Adding 12% tax
    for (int i = 0; i < numClasses; ++i) {
        society[i]->applyTaxPolicy(12.0f);
    }
    //Before random event
    for (int i = 0; i < numClasses; ++i) {
        society[i]->displayStatus();
    }
    //Random event...
    randomEvent(society, numClasses);
    cout << endl;
    //After event
    for (int i = 0; i < numClasses; ++i) {
        society[i]->displayStatus();
    }

    cout << "\nTotal population: " << Tpopulation << endl;
    for (int i = 0; i < numClasses; ++i)
        delete society[i];
    delete[] society;

    cout << "\n-----------------------------\n";

    cout << "=== Stronghold: Army System ===\n\n";

    // Army units
    cout << "Enter no. of Infantry: ";
    cin >> x;
    x = abs(x);
    ArmyUnit* infantry = new Infantry(x);
    cout << "Enter no. of Cavalry: ";
    cin >> x;
    x = abs(x);
    ArmyUnit* cavalry = new Cavalry(x);
    cout << "Enter no. of Archer: ";
    cin >> x;
    x = abs(x);
    ArmyUnit* archers = new Archer(x);

    //Before training
    cout << "\nInitial Army Status:\n";
    infantry->display();
    cout << endl;
    cavalry->display();
    cout << endl;
    archers->display();
    cout << "\n-----------------------------\n";

    // Training...
    cout << "\nTraining All Units:\n";
    infantry->train();
    cavalry->train();
    archers->train();

    //After training
    cout << "\nUpdated Army Status:\n";
    infantry->display();
    cout << endl;
    cavalry->display();
    cout << endl;
    archers->display();
    cout << "\n-----------------------------\n";

    delete infantry;
    delete cavalry;
    delete archers;

    cout << "\nArmy system test complete.\n";

    cout << "\n-----------------------------\n\n";

    //Economy & Taxation System

    Economy* eco = new Economy();
    
    eco->showEconomy();
    eco->collectTaxes(5000, 2.5, 0.4);
    eco->applyCorruptionLoss();
    eco->printMoney(2000);
    eco->applyInflation();
    eco->spendOnServices();
    eco->simulateMarketCrash();
    eco->showEconomy();

    delete eco;

    cout << "\n-----------------------------\n\n";
    
    //Election system

    ElectionSystem electionSystem;

    // Elections

    cout << "Conducting election...\n";
    electionSystem.conductElection();
    electionSystem.showCurrentKing();

    //Rebeliation

    cout << "\n\nPerforming coup...\n";
    electionSystem.performCoup();
    electionSystem.showCurrentKing();

    //Assination

    cout << "\n\nSimulating assassination...\n";
    electionSystem.simulateAssassination();
    electionSystem.showCurrentKing();

    cout << "\nCurrent kingis now King Moeen with level 5\n" << endl;

    cout << "\n-----------------------------\n\n";

    // Banking and corruption system
    
    //Starting balance and treasury balance
    BankingCorruptionSystem system(1000, 5000);

    // status displaying...
    system.displayStatus();

    // taking loan
     // Loan amount, interest rate, term
    float a, b, c;
    cout << "Enter Loan amount: ";
    cin >> a;
    a = abs(a);
    cout << "Enter interest rate: ";
    cin >> b;
    b = abs(b);
    cout << "Enter term: ";
    cin >> c;
    c = abs(c);
    system.takeLoan(a, b, c);
    system.displayStatus();

    // loan repayment
    cout << "Enter amount of loan repayment: ";
    cin >> c;
    c = abs(c);
    system.repayLoan(c);
    system.displayStatus();

    // loan default
    system.defaultLoan();
    system.displayStatus();

    // Corruption
    cout << "Enter amount of Corruption: ";
    cin >> c;
    c = abs(c);
    system.corruptOfficialSteal(c);
    system.displayStatus();

    // Bank heist
    cout << "Enter amount of Bank heist: ";
    cin >> c;
    c = abs(c);
    system.performBankHeist(c);
    system.displayStatus();

    // treasury mismanagement
    system.treasuryMismanagement(300);
    system.displayStatus();

    // Auditing finances
    system.auditFinances();
    system.displayStatus();

    // System is bankrupt or not
    if (system.isBankrupt()) {
        cout << "The system is bankrupt!\n";
    }

    cout << "\n-----------------------------\n\n";
    float d, e, f;
    cout << "Enter amount of wood: ";
    cin >> a;
    a = abs(a);
    cout << "Enter amount of stone: ";
    cin >> b;
    b = abs(b);
    cout << "Enter amount of iron: ";
    cin >> c;
    c = abs(c);
    cout << "Enter amount of gold: ";
    cin >> d;
    d = abs(d);
    cout << "Enter amount of food: ";
    cin >> e;
    e = abs(e);
    cout << "Enter amount of weapons: ";
    cin >> f;
    f = abs(f);

    //Resource supply chain system
    ResourceSupplyChainSystem gameSystem(a, b, c, d, e, f);

    //status displaying...
    gameSystem.displayStatus();

    // Produceing food
    gameSystem.produceFood(200);
    gameSystem.displayStatus();

    //Resources consumption
    cout << " Enter the resources used..." << endl;
    cout << "Enter amount of wood: ";
    cin >> a;
    a = abs(a);
    cout << "Enter amount of stone: ";
    cin >> b;
    b = abs(b);
    cout << "Enter amount of iron: ";
    cin >> c;
    c = abs(c);
    cout << "Enter amount of gold: ";
    cin >> d;
    d = abs(d);
    cout << "Enter amount of food: ";
    cin >> e;
    e = abs(e);
    cout << "Enter amount of weapons: ";
    cin >> f;
    f = abs(f);
    gameSystem.manageResources(a, b, c, d, e, f);
    gameSystem.displayStatus();

    // Security of trade route and trade resources
    gameSystem.secureTradeRoute(true);
    cout << " Enter the trade Resources..." << endl;
    cout << "Enter amount of wood: ";
    cin >> a;
    a = abs(a);
    cout << "Enter amount of stone: ";
    cin >> b;
    b = abs(b);
    cout << "Enter amount of iron: ";
    cin >> c;
    c = abs(c);
    cout << "Enter amount of gold: ";
    cin >> d;
    d = abs(d);
    cout << "Enter amount of food: ";
    cin >> e;
    e = abs(e);
    cout << "Enter amount of weapons: ";
    cin >> f;
    f = abs(f);
    gameSystem.tradeResources(a, b, c, d, e, f);
    gameSystem.displayStatus();

    // Managing resources during war
    gameSystem.startWar();
    cout << " Enter the Resources used in war..." << endl;
    cout << "Enter amount of wood: ";
    cin >> a;
    a = abs(a);
    cout << "Enter amount of stone: ";
    cin >> b;
    b = abs(b);
    cout << "Enter amount of iron: ";
    cin >> c;
    c = abs(c);
    cout << "Enter amount of gold: ";
    cin >> d;
    d = abs(d);
    cout << "Enter amount of food: ";
    cin >> e;
    e = abs(e);
    cout << "Enter amount of weapons: ";
    cin >> f;
    f = abs(f);
    gameSystem.manageResources(a, b, c, d, e, f);
    gameSystem.displayStatus();

    //Weather effect
    gameSystem.weatherConditionsEffect(true);
    gameSystem.displayStatus();

    // starvation
    if (!gameSystem.isPopulationSurviving()) {
        cout << "The population has perished due to starvation!" << endl;
    }

    cout << "\n-----------------------------\n\n";

    TradeMarketDiplomacySystem sys(100, 200, 300, 400, 500);

    //status displaying...
    sys.displayMarketStatus();

    // Alliance
    sys.engageTradeAgreement(true);
    sys.displayMarketStatus();

    // Fluctuating market prices
    sys.fluctuateMarket();
    sys.displayMarketStatus();

    // Detect smuggling
    sys.smuggling(true);
    sys.displayMarketStatus();

    //Trade sanctions
    sys.imposeTradeSanctions(true);
    sys.displayMarketStatus();

    // Handle merchant guild boycott
    sys.merchantGuildActions(true);
    sys.displayMarketStatus();

    // Breaking alliance
    sys.engageTradeAgreement(false);
    sys.displayMarketStatus();

    MultiplayerSystem P;

    //PLayer names
    string name;
    cout << "Enter the name of player1: ";
    getline(cin, name);
    Player* A = P.addPlayer(name);
    cout << "Enter the name of player2: ";
    getline(cin, name);
    Player* B = P.addPlayer(name);
    cout << "Enter the name of player3: ";
    getline(cin, name);
    Player* C = P.addPlayer(name);

    // alliance
    cout << "Forming alliance between " << A << " and " << B << endl;
    P.formAlliance(A, B);
    P.displayAlliances();

    //negotiations
    P.initiateTextCommunication(A, B, "Shall we trade food and gold?");
    P.initiateTextCommunication(B, A, "Yes, but only if you stop attacking our borders.");

    P.formAlliance(B, C);
    P.breakAlliance(A, B);
    P.displayAlliances();


    return 0;
}
