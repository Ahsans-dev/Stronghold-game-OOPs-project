#include "Header.h"

// Population & Social Structure

SocialClass::SocialClass(string name, int population, float taxRate)
    : name(name), population(population), taxRate(taxRate), satisfaction(100.0f) {
}

void SocialClass::applyTaxPolicy(float newTaxRate) {
    taxRate = newTaxRate;
    satisfaction -= newTaxRate * 0.5;
    if (satisfaction < 0) satisfaction = 0;
}

void SocialClass::displayStatus() const {
    cout << name << " | Population: " << population
        << " | Tax Rate: " << taxRate
        << "% | Satisfaction: " << satisfaction << "%" << endl;
}

int SocialClass::getPopulation() const { return population; }
string SocialClass::getName() const { return name; }

// -------------------- Peasant --------------------

Peasant::Peasant(int population) : SocialClass("Peasants", population, 5.0f) {}

void Peasant::applyTaxPolicy(float newTaxRate) {
    taxRate = newTaxRate;
    satisfaction -= newTaxRate * 0.8f;
    if (satisfaction < 0) satisfaction = 0;
}

void Peasant::respondToCrisis(string crisisType) {
    if (crisisType == "Famine" || crisisType == "Plague") {
        population -= population * 0.2;
        satisfaction -= 30;
    }
}

// -------------------- Merchant --------------------

Merchant::Merchant(int population) : SocialClass("Merchants", population, 10.0f) {}

void Merchant::applyTaxPolicy(float newTaxRate) {
    taxRate = newTaxRate;
    satisfaction -= newTaxRate * 0.6f;
    if (satisfaction < 0) satisfaction = 0;
}

void Merchant::respondToCrisis(string crisisType) {
    if (crisisType == "War") {
        satisfaction -= 15;
    }
    if (crisisType == "Economic Collapse") {
        population -= population * 0.1;
        satisfaction -= 40;
    }
}

// -------------------- Noble --------------------

Noble::Noble(int population) : SocialClass("Nobility", population, 2.0f) {}

void Noble::applyTaxPolicy(float newTaxRate) {
    taxRate = newTaxRate;
    satisfaction -= newTaxRate * 0.3f;
    if (satisfaction < 0) satisfaction = 0;
}

void Noble::respondToCrisis(string crisisType) {
    if (crisisType == "Coup" || crisisType == "Revolution") {
        satisfaction -= 50;
        population -= population * 0.1;
    }
}

// -------------------- Military --------------------

Military::Military(int population) : SocialClass("Military", population, 0.0f) {}

void Military::applyTaxPolicy(float newTaxRate) {
    satisfaction -= newTaxRate * 0.2f;
    if (satisfaction < 0) satisfaction = 0;
}

void Military::respondToCrisis(string crisisType) {
    if (crisisType == "War") {
        population -= population * 0.25;
        satisfaction += 10;
    }
    if (crisisType == "Coup") {
        satisfaction += 20;
    }
}


// random event

void randomEvent(SocialClass** classes, int size) {
    srand(time(0));
    int event = rand() % 3;

    string crisis;
    if (event == 0) crisis = "War";
    else if (event == 1) crisis = "Plague";
    else crisis = "Famine";

    cout << "\nRandom Event: " << crisis << "!\n";

    for (int i = 0; i < size; ++i) {
        classes[i]->respondToCrisis(crisis);
    }
}

// Army System

ArmyUnit::ArmyUnit(const string& type, int count)
    : type(type), count(count), morale(100), payStatus(1) {
}

void ArmyUnit::train() {
    cout << "Training " << count << " " << type << "..." << endl;
    Sleep(3000); // 3 seconds
    morale += 5;
    cout << type << " training complete. Morale increased.\n";
}

void ArmyUnit::display() const {
    cout << "Type: " << type << "\nCount: " << count << "\nMorale: " << morale;
    cout << "\nStatus: " << (payStatus ? "Paid" : "Unpaid") << endl;
}

ArmyUnit::~ArmyUnit() {
    cout << "Disbanding " << type << "...\n";
}

Infantry::Infantry(int count) : ArmyUnit("Infantry", count) {}

void Infantry::train() {
    cout << "Training infantry..." << endl;
    Sleep(2000); // 2 seconds
    morale += 10;
    cout << "Infantry morale: " << morale << endl;
}

Cavalry::Cavalry(int count) : ArmyUnit("Cavalry", count) {}

void Cavalry::train() {
    cout << "Training cavalry..." << endl;
    Sleep(4000); // 4 seconds
    morale += 12;
    cout << "Cavalry morale: " << morale << endl;
}

Archer::Archer(int count) : ArmyUnit("Archer", count) {}

void Archer::train() {
    cout << "Training archers..." << endl;
    Sleep(2500); // 2.5 seconds
    morale += 8;
    cout << "Archer morale: " << morale << endl;
}

// Economy & Taxation System

Economy::Economy() {
    treasury = new float(10000);
    inflationRate = new float(0.02);
    taxRate = new float(0.15);
    corruptionLoss = new float(0.1);
    militaryFunding = new float(2000);
    foodBudget = new float(1500);
    hospitalBudget = new float(1000);
}

Economy::~Economy() {
    delete treasury;
    delete inflationRate;
    delete taxRate;
    delete corruptionLoss;
    delete militaryFunding;
    delete foodBudget;
    delete hospitalBudget;
}

void Economy::collectTaxes(float population, float avgIncome, float nobilityFactor) {
    float baseTax = population * avgIncome * (*taxRate);
    float bonus = nobilityFactor * 500;
    *treasury += baseTax + bonus;
    cout << "Collected Taxes: " << baseTax + bonus << "\n";
}

void Economy::applyCorruptionLoss() {
    float loss = (*treasury) * (*corruptionLoss);
    *treasury -= loss;
    cout << "Corruption Loss: " << loss << "\n";
}

void Economy::printMoney(float amount) {
    *treasury += amount;
    *inflationRate += 0.01;
    cout << "Printed Money: " << amount << "\n";
}

void Economy::applyInflation() {
    float loss = (*treasury) * (*inflationRate);
    *treasury -= loss;
    cout << "Inflation Loss: " << loss << "\n";
}

void Economy::spendOnServices() {
    float totalSpending = *militaryFunding + *foodBudget + *hospitalBudget;
    *treasury -= totalSpending;
    cout << "Spent on Services: " << totalSpending << "\n";
}

void Economy::simulateMarketCrash() {
    srand(static_cast<unsigned>(time(0)));
    if (rand() % 5 == 0) {
        float crashLoss = (*treasury) * 0.3f;
        *treasury -= crashLoss;
        cout << "Market Crash! Treasury lost: " << crashLoss << "\n";
    }
}

void Economy::showEconomy() const {
    cout << "Treasury: " << *treasury << "\n";
    cout << "Inflation Rate: " << *inflationRate << "\n";
    cout << "Tax Rate: " << *taxRate << "\n";
    cout << "Corruption Loss %: " << *corruptionLoss * 100 << "\n";
    cout << "Military Budget: " << *militaryFunding << "\n";
    cout << "Food Budget: " << *foodBudget << "\n";
    cout << "Hospital Budget: " << *hospitalBudget << "\n";
}

// King Election System

King::King(const char* name, int level) {
    this->name = new char[strlen(name) + 1];
    strcpy_s(this->name, strlen(name) + 1, name);
    this->leadershipLevel = level;
}

King::~King() {
    delete[] name;
}

const char* King::getName() const {
    return name;
}

int King::getLeadershipLevel() const {
    return leadershipLevel;
}

// StrongKing Implementation
StrongKing::StrongKing(const char* name) : King(name, 10) {}

void StrongKing::rulePolicies() {
    cout << "Strong King " << getName() << " rules with firm and decisive policies.\n";
}

// WeakKing Implementation
WeakKing::WeakKing(const char* name) : King(name, 3) {}

void WeakKing::rulePolicies() {
    cout << "Weak King " << getName() << " struggles with indecisive and weak policies.\n";
}

// ElectionSystem Implementation
ElectionSystem::ElectionSystem() : currentKing(nullptr) {}

ElectionSystem::~ElectionSystem() {
    delete currentKing;
}

void ElectionSystem::conductElection() {
    delete currentKing;
    if (rand() % 2 == 0) {
        currentKing = new StrongKing("King Arthur");
    }
    else {
        currentKing = new WeakKing("King Charles");
    }
}

void ElectionSystem::performCoup() {
    delete currentKing;
    currentKing = new StrongKing("King Alexander");
}

void ElectionSystem::simulateAssassination() {
    delete currentKing;
    currentKing = nullptr;
}

void ElectionSystem::showCurrentKing() {
    if (currentKing) {
        cout << "Current King: " << currentKing->getName() << " with leadership level " << currentKing->getLeadershipLevel() << "\n";
        currentKing->rulePolicies();
    }
    else {
        cout << "There is no current king.\n";
    }
}

//Banking & Corruption System

BankingCorruptionSystem::BankingCorruptionSystem(float initialBalance, float treasuryBalance)
    : currentBalance(initialBalance), treasuryBalance(treasuryBalance), loanAmount(0), interestRate(0), loanTerm(0),
    loanDefaulted(false), auditFailed(false), corruptOfficials(false), bankHeistOccurred(false) {
}

BankingCorruptionSystem::~BankingCorruptionSystem() {}

void BankingCorruptionSystem::takeLoan(float amount, float rate, int term) {
    loanAmount = amount;
    interestRate = rate;
    loanTerm = term;
    loanDefaulted = false;
    cout << "Loan taken: Amount = " << loanAmount << ", Interest rate = " << interestRate << "%, Term = " << loanTerm << " months\n";
}

void BankingCorruptionSystem::repayLoan(float payment) {
    if (loanAmount > 0) {
        loanAmount -= payment;
        cout << "Repayment made: " << payment << ". Remaining loan amount: " << loanAmount << "\n";
        if (loanAmount <= 0) {
            loanAmount = 0;
            cout << "Loan repaid successfully!\n";
        }
    }
    else {
        cout << "No loan to repay.\n";
    }
}

void BankingCorruptionSystem::defaultLoan() {
    if (loanAmount > 0) {
        loanDefaulted = true;
        currentBalance -= loanAmount;
        treasuryBalance -= loanAmount;
        cout << "Loan defaulted! Assets seized! Economic collapse imminent.\n";
    }
}

void BankingCorruptionSystem::auditFinances() {
    auditFailed = (rand() % 2 == 0);
    if (auditFailed) {
        cout << "Audit failed! Resources spent on audit: 50\n";
        currentBalance -= 50;
    }
    else {
        cout << "Audit successful!\n";
    }
}

void BankingCorruptionSystem::corruptOfficialSteal(float amount) {
    corruptOfficials = true;
    treasuryBalance -= amount;
    cout << "Corrupt official stole: " << amount << " from the treasury.\n";
}

void BankingCorruptionSystem::performBankHeist(float amount) {
    bankHeistOccurred = true;
    currentBalance -= amount;
    cout << "Bank heist occurred! Loss of " << amount << " from the bank.\n";
}

void BankingCorruptionSystem::treasuryMismanagement(float loss) {
    treasuryBalance -= loss;
    cout << "Treasury mismanagement led to a loss of " << loss << ".\n";
}

void BankingCorruptionSystem::displayStatus() {
    cout << "\n--- Banking System Status ---\n";
    cout << "Current Balance: " << currentBalance << "\n";
    cout << "Treasury Balance: " << treasuryBalance << "\n";
    cout << "Loan Remaining: " << loanAmount << "\n";
    cout << "Loan Defaulted: " << (loanDefaulted ? "Yes" : "No") << "\n";
    cout << "Audit Failed: " << (auditFailed ? "Yes" : "No") << "\n";
    cout << "Corrupt Officials: " << (corruptOfficials ? "Yes" : "No") << "\n";
    cout << "Bank Heist Occurred: " << (bankHeistOccurred ? "Yes" : "No") << "\n";
    cout << "--- End Status ---\n";
}

bool BankingCorruptionSystem::isLoanDefaulted() {
    return loanDefaulted;
}

bool BankingCorruptionSystem::isBankrupt() {
    return currentBalance <= 0 || treasuryBalance <= 0;
}

//Resources & Supply Chain System

ResourceSupplyChainSystem::ResourceSupplyChainSystem(float initialWood, float initialStone, float initialIron,
    float initialGold, float initialFood, float initialWeapons)
    : wood(initialWood), stone(initialStone), iron(initialIron), gold(initialGold),
    food(initialFood), weapons(initialWeapons), populationSurvives(true), tradeRouteSecure(true),
    warOngoing(false), weatherConditionsBad(false) {
}

ResourceSupplyChainSystem::~ResourceSupplyChainSystem() {}

void ResourceSupplyChainSystem::manageResources(float woodConsumed, float stoneConsumed, float ironConsumed,
    float goldConsumed, float foodConsumed, float weaponsUsed) {
    wood -= woodConsumed;
    stone -= stoneConsumed;
    iron -= ironConsumed;
    gold -= goldConsumed;
    food -= foodConsumed;
    weapons -= weaponsUsed;

    if (food <= 0) {
        populationSurvives = false;
        cout << "Food shortage! Population is starving!\n";
    }

    if (wood <= 0 || stone <= 0 || iron <= 0 || gold <= 0 || weapons <= 0) {
        cout << "Critical resource shortage! You are in danger of collapse!\n";
    }
}

void ResourceSupplyChainSystem::produceFood(float foodProduced) {
    if (!populationSurvives) {
        cout << "Population cannot survive due to starvation!\n";
        return;
    }
    food += foodProduced;
    cout << "Produced " << foodProduced << " units of food.\n";
}

void ResourceSupplyChainSystem::tradeResources(float woodAmount, float stoneAmount, float ironAmount,
    float goldAmount, float foodAmount, float weaponsAmount) {
    if (!tradeRouteSecure) {
        cout << "Trade route is insecure! Trade failed.\n";
        return;
    }

    wood -= woodAmount;
    stone -= stoneAmount;
    iron -= ironAmount;
    gold -= goldAmount;
    food -= foodAmount;
    weapons -= weaponsAmount;

    cout << "Traded resources successfully!\n";
}

void ResourceSupplyChainSystem::secureTradeRoute(bool isSecure) {
    tradeRouteSecure = isSecure;
    if (isSecure) {
        cout << "Trade route is secure!\n";
    }
    else {
        cout << "Trade route is insecure! Beware of enemy attacks!\n";
    }
}

void ResourceSupplyChainSystem::startWar() {
    warOngoing = true;
    cout << "War has started! Resources will be drained quickly.\n";
}

void ResourceSupplyChainSystem::weatherConditionsEffect(bool badWeather) {
    weatherConditionsBad = badWeather;
    if (badWeather) {
        cout << "Bad weather conditions (droughts or harsh winter) are affecting food production!\n";
        food *= 0.7;
    }
}

void ResourceSupplyChainSystem::displayStatus() {
    cout << "\n--- Resource and Supply Chain System Status ---\n";
    cout << "Wood: " << wood << ", Stone: " << stone << ", Iron: " << iron << ", Gold: " << gold << "\n";
    cout << "Food: " << food << ", Weapons: " << weapons << "\n";
    cout << "Population Survives: " << (populationSurvives ? "Yes" : "No") << "\n";
    cout << "Trade Route Secure: " << (tradeRouteSecure ? "Yes" : "No") << "\n";
    cout << "War Ongoing: " << (warOngoing ? "Yes" : "No") << "\n";
    cout << "Weather Conditions Bad: " << (weatherConditionsBad ? "Yes" : "No") << "\n";
    cout << "--- End Status ---\n";
}

bool ResourceSupplyChainSystem::isPopulationSurviving() {
    return populationSurvives;
}

bool ResourceSupplyChainSystem::isTradeRouteSecure() {
    return tradeRouteSecure;
}

bool ResourceSupplyChainSystem::isWarOngoing() {
    return warOngoing;
}

bool ResourceSupplyChainSystem::areWeatherConditionsBad() {
    return weatherConditionsBad;
}

//Trade, Market & Diplomacy System

TradeMarketDiplomacySystem::TradeMarketDiplomacySystem(float initialWoodPrice, float initialStonePrice, float initialIronPrice,
    float initialGoldPrice, float initialFoodPrice)
    : marketPriceWood(initialWoodPrice), marketPriceStone(initialStonePrice), marketPriceIron(initialIronPrice),
    marketPriceGold(initialGoldPrice), marketPriceFood(initialFoodPrice), tradeSanctions(false), smugglingDetected(false),
    merchantGuildBoycott(false) {
}

TradeMarketDiplomacySystem::~TradeMarketDiplomacySystem() {}

void TradeMarketDiplomacySystem::fluctuateMarket() {
    marketPriceWood *= (1 + (rand() % 21 - 10) / 100.0);  // Random fluctuation between -10% and +10%
    marketPriceStone *= (1 + (rand() % 21 - 10) / 100.0);
    marketPriceIron *= (1 + (rand() % 21 - 10) / 100.0);
    marketPriceGold *= (1 + (rand() % 21 - 10) / 100.0);
    marketPriceFood *= (1 + (rand() % 21 - 10) / 100.0);

    cout << "Market prices have fluctuated!" << endl;
}

void TradeMarketDiplomacySystem::engageTradeAgreement(bool isAlliance) {
    if (isAlliance) {
        cout << "Trade agreement/Alliance formed!" << endl;
    }
    else {
        cout << "Trade agreement/Alliance broken!" << endl;
    }
}

void TradeMarketDiplomacySystem::smuggling(bool detected) {
    smugglingDetected = detected;
    if (detected) {
        cout << "Smuggling detected! Fines are imposed." << endl;
    }
    else {
        cout << "No smuggling detected." << endl;
    }
}

void TradeMarketDiplomacySystem::imposeTradeSanctions(bool sanctions) {
    tradeSanctions = sanctions;
    if (sanctions) {
        cout << "Trade sanctions have been imposed!" << endl;
    }
    else {
        cout << "Trade sanctions lifted." << endl;
    }
}

void TradeMarketDiplomacySystem::merchantGuildActions(bool boycott) {
    merchantGuildBoycott = boycott;
    if (boycott) {
        cout << "Merchant guild is boycotting due to unfair prices!" << endl;
    }
    else {
        cout << "Merchant guild is satisfied with fair prices." << endl;
    }
}

void TradeMarketDiplomacySystem::displayMarketStatus() {
    cout << "\n--- Market and Diplomacy Status ---\n";
    cout << "Wood price: " << marketPriceWood << ", Stone price: " << marketPriceStone << ", Iron price: " << marketPriceIron << "\n";
    cout << "Gold price: " << marketPriceGold << ", Food price: " << marketPriceFood << "\n";
    cout << "Trade Sanctions: " << (tradeSanctions ? "Yes" : "No") << "\n";
    cout << "Smuggling Detected: " << (smugglingDetected ? "Yes" : "No") << "\n";
    cout << "Merchant Guild Boycott: " << (merchantGuildBoycott ? "Yes" : "No") << "\n";
    cout << "--- End Status ---\n";
}

bool TradeMarketDiplomacySystem::areTradeSanctionsImposed() {
    return tradeSanctions;
}

bool TradeMarketDiplomacySystem::isSmugglingDetected() {
    return smugglingDetected;
}

bool TradeMarketDiplomacySystem::isMerchantGuildBoycotting() {
    return merchantGuildBoycott;
}

//Multiplayer System & Text Communication


Player::Player() {
    name = "";
    inAlliance = false;
}

Player::Player(string playerName) {
    name = playerName;
    inAlliance = false;
}

string Player::getName() {
    return name;
}

void Player::setName(string playerName) {
    name = playerName;
}

void Player::formAlliance() {
    inAlliance = true;
}

void Player::breakAlliance() {
    inAlliance = false;
}

bool Player::hasAlliance() {
    return inAlliance;
}

// MultiplayerSystem Implementation

MultiplayerSystem::MultiplayerSystem() {
    playerCount = 0;
    allianceCount = 0;
    for (int i = 0; i < 10; i++) {
        players[i] = nullptr;
    }
}

MultiplayerSystem::~MultiplayerSystem() {
    for (int i = 0; i < playerCount; i++) {
        delete players[i];
    }
}

Player* MultiplayerSystem::addPlayer(string name) {
    if (playerCount >= 10) {
        cout << "Max players reached!" << endl;
        return nullptr;
    }
    players[playerCount] = new Player(name);
    return players[playerCount++];
}

void MultiplayerSystem::formAlliance(Player* p1, Player* p2) {
    if (allianceCount >= 10) {
        cout << "Max alliances reached!" << endl;
        return;
    }
    if (isInAlliance(p1, p2)) {
        cout << p1->getName() << " and " << p2->getName() << " are already allies." << endl;
        return;
    }
    alliances[allianceCount][0] = p1;
    alliances[allianceCount][1] = p2;
    p1->formAlliance();
    p2->formAlliance();
    allianceCount++;
    cout << p1->getName() << " and " << p2->getName() << " formed an alliance!" << endl;
}

void MultiplayerSystem::breakAlliance(Player* p1, Player* p2) {
    for (int i = 0; i < allianceCount; i++) {
        if ((alliances[i][0] == p1 && alliances[i][1] == p2) ||
            (alliances[i][0] == p2 && alliances[i][1] == p1)) {
            p1->breakAlliance();
            p2->breakAlliance();
            cout << p1->getName() << " and " << p2->getName() << " broke their alliance!" << endl;
            for (int j = i; j < allianceCount - 1; j++) {
                alliances[j][0] = alliances[j + 1][0];
                alliances[j][1] = alliances[j + 1][1];
            }
            allianceCount--;
            return;
        }
    }
    cout << "No alliance to break." << endl;
}

bool MultiplayerSystem::isInAlliance(Player* p1, Player* p2) {
    for (int i = 0; i < allianceCount; i++) {
        if ((alliances[i][0] == p1 && alliances[i][1] == p2) ||
            (alliances[i][0] == p2 && alliances[i][1] == p1)) {
            return true;
        }
    }
    return false;
}

void MultiplayerSystem::initiateTextCommunication(Player* sender, Player* receiver, string message) {
    cout << sender->getName() << " to " << receiver->getName() << ": " << message << endl;
}

void MultiplayerSystem::displayAlliances() {
    cout << "\nCurrent Alliances:\n";
    for (int i = 0; i < allianceCount; i++) {
        cout << alliances[i][0]->getName() << " <--> " << alliances[i][1]->getName() << endl;
    }
    if (allianceCount == 0) {
        cout << "No alliances.\n";
    }
}