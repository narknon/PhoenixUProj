#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "GameplayTagContainer.h"
#include "EProductionStatus.h"
#include "WorldEventDataRow.h"
#include "WorldEventCoreMechanics.generated.h"

class AWorldEventLocationActor;

UCLASS(Blueprintable)
class AWorldEventCoreMechanics : public AActor {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AWorldEventLocationActor* GeneralLocationActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* TeleportLocationActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ProductionStatusMask;
    
public:
    AWorldEventCoreMechanics();
protected:
    UFUNCTION(BlueprintCallable)
    void ToggleMaskValue(EProductionStatus Status);
    
private:
    UFUNCTION(BlueprintCallable)
    TArray<FName> SortAlphabetically(TArray<FName> unsortedArray);
    
    UFUNCTION(BlueprintCallable)
    void SetTag(FGameplayTag Tag);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool RowMatchesProductionFilter(const FWorldEventDataRow& Row);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnWorldEventLoaded(AWorldEventLocationActor* Location, const FWorldEventDataRow& Row);
    
    UFUNCTION(BlueprintCallable)
    void OnPreviewLevelLoaded();
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnPlayerReturned();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool MaskMatchesFilter(EProductionStatus Status);
    
private:
    UFUNCTION(BlueprintCallable)
    void LoadAndTeleport(FName weName);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void GetPositionAndRotation(int32 Index, int32 Count, const AActor* StartLocation, int32 rowLength, FVector axisAlignment, FVector& OutPosition, FRotator& OutRotation, int32 Width);
    
    UFUNCTION(BlueprintCallable)
    TArray<FGameplayTag> GetLocationTags();
    
};

