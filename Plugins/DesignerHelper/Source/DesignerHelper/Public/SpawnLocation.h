#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DbSingleColumnInfo.h"
#include "Engine/TargetPoint.h"
#include "ESpawnVolumeType.h"
#include "SpawnProperties.h"
#include "SpawnerActorSpawnedSignatureDelegate.h"
#include "SpawnerFinishedSpawningSignatureDelegate.h"
#include "SpawnLocation.generated.h"

class UPrimitiveComponent;
class UTextRenderComponent;

UCLASS(Blueprintable)
class DESIGNERHELPER_API ASpawnLocation : public ATargetPoint {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSpawnerActorSpawnedSignature OnActorSpawned;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSpawnerFinishedSpawningSignature OnFinishedSpawning;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDbSingleColumnInfo SpawnCategoryType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FDbSingleColumnInfo> AdditionalSpawnCategoryTypes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText Description;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ESpawnVolumeType SpawnVolumeType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPrimitiveComponent* SpawnVolume;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnableScatterSampling;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bEnableRandomRotation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSpawnOnNavMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bForceSpawnOnFloor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 GridCols;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 GridRows;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D ScatterVariance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTextRenderComponent* DebugTextVisualizer;
    
public:
    ASpawnLocation();
    UFUNCTION(BlueprintCallable)
    void StopSpawning(const FName& GroupIn);
    
    UFUNCTION(BlueprintCallable)
    void StartSpawningUsingProbability(const FSpawnProperties& SpawnProperiesIn, const FName& GroupIn, float& SpawnProbability, const int32& NumActorsPerClassIn, int32 InFirstActorGroupIndex);
    
    UFUNCTION(BlueprintCallable)
    void StartSpawning(const FSpawnProperties& SpawnProperiesIn, const FName& GroupIn);
    
    UFUNCTION(BlueprintCallable)
    void SetSpawnCategorySelection(const FString& InSpawnCatType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsSpawning(const FName& GroupIn) const;
    
    UFUNCTION(BlueprintCallable)
    void InitScatterGrid();
    
    UFUNCTION(BlueprintCallable)
    void CacheVolumeBounds();
    
};

