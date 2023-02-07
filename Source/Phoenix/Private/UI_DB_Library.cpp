#include "UI_DB_Library.h"

class AActor;
class UObject;
class UStationComponent;

bool UUI_DB_Library::UnlockStationBP(UStationComponent* StationComponent) {
    return false;
}

bool UUI_DB_Library::TargetHasConversationEntries(FName TargetActor, AActor* InTargetActor, bool& MissionInteraction) {
    return false;
}

void UUI_DB_Library::SetSystemSubtitles(bool SubtitlesEnabled) {
}

bool UUI_DB_Library::LockStation(UStationComponent* StationComponent, UObject* PlayerActor) {
    return false;
}

TArray<FString> UUI_DB_Library::GetUsabilityMissionList() {
    return TArray<FString>();
}

bool UUI_DB_Library::GetSystemSubtitles() {
    return false;
}

FName UUI_DB_Library::GetSubtypeFromSubjectName(FName Subject) {
    return NAME_None;
}

FString UUI_DB_Library::GetSubjectCategoryFromSubject(FName Subject) {
    return TEXT("");
}

bool UUI_DB_Library::GetSocialActionChoicesBP(TArray<FStationQueryData>& StationQueryData, UStationComponent* StationComponent, UObject* RequestingObject) {
    return false;
}

bool UUI_DB_Library::GetRichPaperData(const FString& RichPaperID, const FString& sender, FString& o_richPaperType, FString& o_imageName, FString& o_headerTextKey, FString& o_bodyTextKey, FString& o_footerTextKey) {
    return false;
}

int32 UUI_DB_Library::GetMaxHealthForLevel(int32 Level) {
    return 0;
}

void UUI_DB_Library::GetLevelRequiermentsForItem(const FString& Item, int32& outLevel, bool& outUsable) {
}

bool UUI_DB_Library::GetIsCustomizable(const FString& SubtypeID) {
    return false;
}

FName UUI_DB_Library::GetHouseIDFromSubjectName(FName Subject) {
    return NAME_None;
}

float UUI_DB_Library::GetHealthCooldown() {
    return 0.0f;
}

TArray<FName> UUI_DB_Library::GetFrontendLevelList() {
    return TArray<FName>();
}

TArray<FName> UUI_DB_Library::GetDeveloperLevelList() {
    return TArray<FName>();
}

void UUI_DB_Library::GetDefaultInventoryHolderID(const FString& Item, FString& HolderID) {
}

void UUI_DB_Library::GetCompendiumSubjectFacts(FName Category, FName Subject, FFactSheetResult& FactSheet) {
}

void UUI_DB_Library::GetCompendiumPeopleSubjects(TArray<FPeopleInformation>& People, TArray<FName>& PeopleNames, int32& TotalPeople) {
}

void UUI_DB_Library::GetCompendiumCategorySubjects(FName Category, TArray<FName>& KnownSubjects, TArray<FName>& UnknownSubjects) {
}

void UUI_DB_Library::GetCompendiumCategories(TArray<FName>& Categories) {
}

void UUI_DB_Library::GetActorsKnownSubjects(FName Actor, TArray<FFactInformation>& Subjects, TArray<FFactInformation>& SubjectsAlreadyKnown) {
}

bool UUI_DB_Library::ChooseStationQueryDataBP(AActor* InActor, UObject* ObjectComponent, const EStationInteraction InStationInteractionType, const FName InActionName, const int32 InConnectionIndex) {
    return false;
}

UUI_DB_Library::UUI_DB_Library() {
}

