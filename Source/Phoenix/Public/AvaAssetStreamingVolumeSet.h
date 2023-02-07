#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AvaStreamingVolumeSet.h"
#include "AvaAssetStreamingVolumeSet.generated.h"

class AActor;
class UObject;

UCLASS(Blueprintable)
class AAvaAssetStreamingVolumeSet : public AAvaStreamingVolumeSet {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftObjectPtr<UObject>> AssetsToStream;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* AssetOwner;
    
    AAvaAssetStreamingVolumeSet();
    UFUNCTION(BlueprintCallable)
    void SetAssetOwner(AActor* NewOwner);
    
    UFUNCTION(BlueprintCallable)
    TArray<FTransform> GetAssetTransforms();
    
    UFUNCTION(BlueprintCallable)
    TArray<TSoftObjectPtr<UObject>> GetAssetsToStream();
    
    UFUNCTION(BlueprintCallable)
    AActor* GetAssetOwner();
    
};

