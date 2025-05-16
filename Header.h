#pragma once

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <windows.h> // for Sleep()

using namespace std;

class SocialClass {
protected:
    string name;
    int population;
    float taxRate;
    float satisfaction;
public:
    SocialClass(string name, int population, float taxRate);

    virtual void applyTaxPolicy(float newTaxRate);
    virtual void respondToCrisis(string crisisType) = 0;
    virtual void displayStatus() const;

    int getPopulation() const;
    string getName() const;

    virtual ~SocialClass() {}
};

class Peasant : public SocialClass {
public:
    Peasant(int population);
    void applyTaxPolicy(float newTaxRate) override;
    void respondToCrisis(string crisisType) override;
};

class Merchant : public SocialClass {
public:
    Merchant(int population);
    void applyTaxPolicy(float newTaxRate) override;
    void respondToCrisis(string crisisType) override;
};

class Noble : public SocialClass {
public:
    Noble(int population);
    void applyTaxPolicy(float newTaxRate) override;
    void respondToCrisis(string crisisType) override;
};

class Military : public SocialClass {
public:
    Military(int population);
    void applyTaxPolicy(float newTaxRate) override;
    void respondToCrisis(string crisisType) override;
};

void randomEvent(SocialClass** classes, int size);

class ArmyUnit {
protected:
    string type;
    int count;
    int morale;
    int payStatus; // 0 = unpaid, 1 = paid

public:
    ArmyUnit(const string& type, int count);
    virtual void train();
    virtual void display() const;
    virtual ~ArmyUnit();
};

class Infantry : public ArmyUnit {
public:
    Infantry(int count);
    void train() override;
};

class Cavalry : public ArmyUnit {
public:
    Cavalry(int count);
    void train() override;
};

class Archer : public ArmyUnit {
public:
    Archer(int count);
    void train() override;
};

class Economy {
private:
    float* treasury;
    float* inflationRate;
    float* taxRate;
    float* corruptionLoss;
    float* militaryFunding;
    float* foodBudget;
    float* hospitalBudget;

public:
    Economy();
    ~Economy();

    void collectTaxes(float population, float avgIncome, float nobilityFactor);
    void applyCorruptionLoss();
    void printMoney(float amount);
    void applyInflation();
    void spendOnServices();
    void simulateMarketCrash();
    void showEconomy() const;
};

class King {
protected:
    char* name;
    int leadershipLevel;
public:
    King(const char* name, int level);
    virtual ~King();

    virtual void rulePolicies() = 0;
    const char* getName() const;
    int getLeadershipLevel() const;
};

class StrongKing : public King {
public:
    StrongKing(const char* name);
    void rulePolicies() override;
};

class WeakKing : public King {
public:
    WeakKing(const char* name);
    void rulePolicies() override;
};

class ElectionSystem {
private:
    King* currentKing;

public:
    ElectionSystem();
    ~ElectionSystem();

    void conductElection();
    void performCoup();
    void simulateAssassination();
    void showCurrentKing();
};


class BankingCorruptionSystem {
private:
    float loanAmount;
    float interestRate;
    int loanTerm; // in months
    float currentBalance;
    bool loanDefaulted;
    float treasuryBalance;
    bool auditFailed;
    bool corruptOfficials;
    bool bankHeistOccurred;

public:
    BankingCorruptionSystem(float initialBalance, float treasuryBalance);
    ~BankingCorruptionSystem();

    void takeLoan(float amount, float rate, int term);
    void repayLoan(float payment);
    void defaultLoan();
    void auditFinances();
    void corruptOfficialSteal(float amount);
    void performBankHeist(float amount);
    void treasuryMismanagement(float loss);
    void displayStatus();
    bool isLoanDefaulted();
    bool isBankrupt();
};

class ResourceSupplyChainSystem {
private:
    float wood, stone, iron, gold, food, weapons;
    bool populationSurvives;
    bool tradeRouteSecure;
    bool warOngoing;
    bool weatherConditionsBad;

public:
    ResourceSupplyChainSystem(float initialWood, float initialStone, float initialIron,
        float initialGold, float initialFood, float initialWeapons);
    ~ResourceSupplyChainSystem();

    void manageResources(float woodConsumed, float stoneConsumed, float ironConsumed,
        float goldConsumed, float foodConsumed, float weaponsUsed);
    void produceFood(float foodProduced);
    void tradeResources(float woodAmount, float stoneAmount, float ironAmount,
        float goldAmount, float foodAmount, float weaponsAmount);
    void secureTradeRoute(bool isSecure);
    void startWar();
    void weatherConditionsEffect(bool badWeather);
    void displayStatus();
    bool isPopulationSurviving();
    bool isTradeRouteSecure();
    bool isWarOngoing();
    bool areWeatherConditionsBad();
};

class TradeMarketDiplomacySystem {
private:
    float marketPriceWood, marketPriceStone, marketPriceIron, marketPriceGold, marketPriceFood;
    bool tradeSanctions;
    bool smugglingDetected;
    bool merchantGuildBoycott;

public:
    TradeMarketDiplomacySystem(float initialWoodPrice, float initialStonePrice, float initialIronPrice,
        float initialGoldPrice, float initialFoodPrice);
    ~TradeMarketDiplomacySystem();

    void fluctuateMarket();
    void engageTradeAgreement(bool isAlliance);
    void smuggling(bool detected);
    void imposeTradeSanctions(bool sanctions);
    void merchantGuildActions(bool boycott);

    void displayMarketStatus();
    bool areTradeSanctionsImposed();
    bool isSmugglingDetected();
    bool isMerchantGuildBoycotting();
};

class Player {
private:
    string name;
    bool inAlliance;

public:
    Player();
    Player(string playerName);
    string getName();
    void setName(string playerName);
    void formAlliance();
    void breakAlliance();
    bool hasAlliance();
};

class MultiplayerSystem {
private:
    Player* players[10];
    int playerCount;
    Player* alliances[10][2];
    int allianceCount;

public:
    MultiplayerSystem();
    ~MultiplayerSystem();

    Player* addPlayer(string name);
    void formAlliance(Player* p1, Player* p2);
    void breakAlliance(Player* p1, Player* p2);
    void initiateTextCommunication(Player* sender, Player* receiver, string message);
    void displayAlliances();
    bool isInAlliance(Player* p1, Player* p2);
};