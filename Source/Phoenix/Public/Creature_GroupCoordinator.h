#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Creature_GroupCoordination_LocationTag.h"
#include "Creature_GroupCoordinator.generated.h"

class AActor;

UCLASS(Blueprintable)
class PHOENIX_API UCreature_GroupCoordinator : public UObject {
    GENERATED_BODY()
public:
    UCreature_GroupCoordinator();
    UFUNCTION(BlueprintCallable)
    static void SetTagLimitOnActor(AActor* Subject, FName Identifier, int32 Limit);
    
    UFUNCTION(BlueprintCallable)
    static bool RemoveTagsWithIDFromActor(AActor* Subject, FName Identifier);
    
    UFUNCTION(BlueprintCallable)
    static void RemoveTagLimitOnActor(AActor* Subject, FName Identifier);
    
    UFUNCTION(BlueprintCallable)
    static void RemoveAllLocationTagsWithIDAndOwner(FName Identifier, AActor* Owner);
    
    UFUNCTION(BlueprintCallable)
    static void RemoveAllActorTagsWithIDAndOwner(FName Identifier, AActor* Owner);
    
    UFUNCTION(BlueprintCallable)
    static bool RemoveActorTag(AActor* Subject, FName Identifier, AActor* Owner);
    
    UFUNCTION(BlueprintCallable)
    static void RegisterLocationTag(FVector Location, FName Identifier, float Radius, float LifeTime, AActor* Owner);
    
    UFUNCTION(BlueprintCallable)
    static bool RegisterActorTag(AActor* Subject, FName Identifier, float LifeTime, AActor* Owner);
    
    UFUNCTION(BlueprintCallable)
    static int32 GetTagLimitOnActor(AActor* Subject, FName Identifier);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool GetDoesLocationTagExistIgnoreOwner(FVector Location, FName Identifier, float SearchRadius, AActor* OwnerToIgnore);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool GetDoesLocationTagExistFromOwner(FVector Location, FName Identifier, float SearchRadius, AActor* Owner);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool GetDoesLocationTagExist(FVector Location, FName Identifier, float SearchRadius);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool GetDoesActorTagExistIgnoreOwner(const AActor* Subject, FName Identifier, AActor* OwnerToIgnore);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool GetDoesActorTagExistFromOwner(const AActor* Subject, FName Identifier, AActor* Owner);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool GetDoesActorTagExist(const AActor* Subject, FName Identifier);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static TArray<FCreature_GroupCoordination_LocationTag> GetAllOverlappingLocationTags(FVector Location, FName Identifier, float SearchRadius);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool GetActorTagLifetimeLeftFromOwner(const AActor* Subject, FName Identifier, AActor* Owner, float& OutTagAge);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool GetActorTagAgeFromOwner(const AActor* Subject, FName Identifier, AActor* Owner, float& OutTagAge);
    
};

