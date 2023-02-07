#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AvaStreamingVolumeComponentBase.h"
#include "AvaAssetStreamingVolumeComponent.generated.h"

class AActor;
class UObject;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UAvaAssetStreamingVolumeComponent : public UAvaStreamingVolumeComponentBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftObjectPtr<UObject>> AssetsToStream;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* AssetOwner;
    
    UAvaAssetStreamingVolumeComponent();
    UFUNCTION(BlueprintCallable)
    void SetAssetOwner(AActor* NewOwner);
    
    UFUNCTION(BlueprintCallable)
    TArray<FTransform> GetAssetTransforms();
    
    UFUNCTION(BlueprintCallable)
    TArray<TSoftObjectPtr<UObject>> GetAssetsToStream();
    
    UFUNCTION(BlueprintCallable)
    AActor* GetAssetOwner();
    
};

