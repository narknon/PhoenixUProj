#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "CollectionCategory.h"
#include "EKnowledgeAction.h"
#include "EKnowledgeLevel.h"
#include "KnowledgeAuthority.h"
#include "KnowledgeManager.generated.h"

class AActor;
class UKnowledgeManager;

UCLASS(Blueprintable)
class UKnowledgeManager : public UObject {
    GENERATED_BODY()
public:
    UKnowledgeManager();
    UFUNCTION(BlueprintCallable)
    void UpdateGoldChestChallenge(AActor* Chest);
    
    UFUNCTION(BlueprintCallable)
    void OnSaveGameLoaded();
    
    UFUNCTION(BlueprintCallable)
    void OnNewGame();
    
    UFUNCTION(BlueprintCallable, Exec)
    void KnowledgeLevelSet(const FString& KnowledgeCard, const FString& Level);
    
    UFUNCTION(BlueprintCallable)
    bool IsSubjectCompletelyKnown(FName ObjectID);
    
    UFUNCTION(BlueprintCallable)
    FName IsKnowledgeSubject(FName ObjectID, bool IsRecursion);
    
    UFUNCTION(BlueprintCallable)
    FName IsGroupMember(FName ObjectID);
    
    UFUNCTION(BlueprintCallable)
    bool IsFactKnown(FName ObjectID, FName FactColumnID, EKnowledgeLevel& KnowledgeLevel);
    
    UFUNCTION(BlueprintCallable)
    float GetSubjectKnowledgePoints(FName ObjectID);
    
    UFUNCTION(BlueprintCallable)
    FName GetSubjectKnowledgeCategory(FName ObjectID);
    
    UFUNCTION(BlueprintCallable)
    FName GetRegionKnowledgeCardFromLocation(FVector Location);
    
    UFUNCTION(BlueprintCallable)
    EKnowledgeLevel GetPlayerKnowledgeLevel(FName ObjectID, FName FactColumnID);
    
    UFUNCTION(BlueprintCallable)
    FName GetNameFromKnowledgeLevel(EKnowledgeLevel KnowledgeLevel);
    
    UFUNCTION(BlueprintCallable)
    TArray<FKnowledgeAuthority> GetKnowledgeAuthority(FName KnowledgeSubjectID);
    
    UFUNCTION(BlueprintCallable)
    TArray<FName> GetGroupMembers(FName ObjectID);
    
    UFUNCTION(BlueprintCallable)
    float GetFieldGuideCompletionPercentage();
    
    UFUNCTION(BlueprintCallable)
    int32 GetCompanionLevel(const FString& CharacterID);
    
    UFUNCTION(BlueprintCallable)
    TMap<FName, FCollectionCategory> GetCollections();
    
    UFUNCTION(BlueprintCallable)
    TArray<FName> GetAllKnowledgeCardsByCategory(const FString& Category);
    
    UFUNCTION(BlueprintCallable)
    TArray<FName> GetAllKnowledgeCards();
    
    UFUNCTION(BlueprintCallable)
    static UKnowledgeManager* Get();
    
    UFUNCTION(BlueprintCallable)
    void GainKnowledgeFromNPC(FName ObjectID, FName NPCID, const bool InDisplayTicker);
    
    UFUNCTION(BlueprintCallable)
    void GainKnowledgeFromAction(FName ObjectID, TEnumAsByte<EKnowledgeAction> KnowledgeAction, const bool InDisplayTicker);
    
    UFUNCTION(BlueprintCallable)
    void GainKnowledgeFact(FName ObjectID, FName FactColumnID, TEnumAsByte<EKnowledgeAction> KnowledgeAction, const bool InDisplayTicker);
    
    UFUNCTION(BlueprintCallable, Exec)
    void CompleteAllKnowledgeCards();
    
    UFUNCTION(BlueprintCallable, Exec)
    void CompleteAllCollections();
    
    UFUNCTION(BlueprintCallable, Exec)
    void AddKnowledgePointsToCard(const FString& KnowledgeCard, float PointsToAdd);
    
    UFUNCTION(BlueprintCallable, Exec)
    void AddKnowledgeFromInventory(const FString& Level);
    
};

