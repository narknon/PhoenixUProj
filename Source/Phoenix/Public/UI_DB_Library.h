#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "EStationInteraction.h"
#include "FactInformation.h"
#include "FactSheetResult.h"
#include "PeopleInformation.h"
#include "StationQueryData.h"
#include "UI_DB_Library.generated.h"

class AActor;
class UObject;
class UStationComponent;

UCLASS(Blueprintable)
class UUI_DB_Library : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UUI_DB_Library();
    UFUNCTION(BlueprintCallable)
    static bool UnlockStationBP(UStationComponent* StationComponent);
    
    UFUNCTION(BlueprintCallable)
    static bool TargetHasConversationEntries(FName TargetActor, AActor* InTargetActor, bool& MissionInteraction);
    
    UFUNCTION(BlueprintCallable)
    static void SetSystemSubtitles(bool SubtitlesEnabled);
    
    UFUNCTION(BlueprintCallable)
    static bool LockStation(UStationComponent* StationComponent, UObject* PlayerActor);
    
    UFUNCTION(BlueprintCallable)
    static TArray<FString> GetUsabilityMissionList();
    
    UFUNCTION(BlueprintCallable)
    static bool GetSystemSubtitles();
    
    UFUNCTION(BlueprintCallable)
    static FName GetSubtypeFromSubjectName(FName Subject);
    
    UFUNCTION(BlueprintCallable)
    static FString GetSubjectCategoryFromSubject(FName Subject);
    
    UFUNCTION(BlueprintCallable)
    static bool GetSocialActionChoicesBP(TArray<FStationQueryData>& StationQueryData, UStationComponent* StationComponent, UObject* RequestingObject);
    
    UFUNCTION(BlueprintCallable)
    static bool GetRichPaperData(const FString& RichPaperID, const FString& sender, FString& o_richPaperType, FString& o_imageName, FString& o_headerTextKey, FString& o_bodyTextKey, FString& o_footerTextKey);
    
    UFUNCTION(BlueprintCallable)
    static int32 GetMaxHealthForLevel(int32 Level);
    
    UFUNCTION(BlueprintCallable)
    static void GetLevelRequiermentsForItem(const FString& Item, int32& outLevel, bool& outUsable);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool GetIsCustomizable(const FString& SubtypeID);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FName GetHouseIDFromSubjectName(FName Subject);
    
    UFUNCTION(BlueprintCallable)
    static float GetHealthCooldown();
    
    UFUNCTION(BlueprintCallable)
    static TArray<FName> GetFrontendLevelList();
    
    UFUNCTION(BlueprintCallable)
    static TArray<FName> GetDeveloperLevelList();
    
    UFUNCTION(BlueprintCallable)
    static void GetDefaultInventoryHolderID(const FString& Item, FString& HolderID);
    
    UFUNCTION(BlueprintCallable)
    static void GetCompendiumSubjectFacts(FName Category, FName Subject, FFactSheetResult& FactSheet);
    
    UFUNCTION(BlueprintCallable)
    static void GetCompendiumPeopleSubjects(TArray<FPeopleInformation>& People, TArray<FName>& PeopleNames, int32& TotalPeople);
    
    UFUNCTION(BlueprintCallable)
    static void GetCompendiumCategorySubjects(FName Category, TArray<FName>& KnownSubjects, TArray<FName>& UnknownSubjects);
    
    UFUNCTION(BlueprintCallable)
    static void GetCompendiumCategories(TArray<FName>& Categories);
    
    UFUNCTION(BlueprintCallable)
    static void GetActorsKnownSubjects(FName Actor, TArray<FFactInformation>& Subjects, TArray<FFactInformation>& SubjectsAlreadyKnown);
    
    UFUNCTION(BlueprintCallable)
    static bool ChooseStationQueryDataBP(AActor* InActor, UObject* ObjectComponent, const EStationInteraction InStationInteractionType, const FName InActionName, const int32 InConnectionIndex);
    
};

