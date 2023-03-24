#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EPSOCachePreviewMode.h"
#include "PreviewAssetTypeData.h"
#include "PSOCachingPreviewActor.generated.h"

class UObject;
class UPrimitiveComponent;

UCLASS(Blueprintable)
class PSOCACHING_API APSOCachingPreviewActor : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EPSOCachePreviewMode PreviewMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 PreviewFramesCount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PreviewTime;
    
    APSOCachingPreviewActor(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void SetupManagedPrimitiveComponent(UPrimitiveComponent* InComponent);
    
private:
    UFUNCTION(BlueprintCallable)
    void ResetStaticMeshPreview(UPrimitiveComponent* Primitive);
    
    UFUNCTION(BlueprintCallable)
    void ResetNiagaraSystemPreview(UPrimitiveComponent* Primitive);
    
public:
    UFUNCTION(BlueprintCallable)
    void RegisterPreviewAssetTypeData(UClass* AssetType, const FPreviewAssetTypeData& AssetTypeData);
    
    UFUNCTION(BlueprintCallable)
    void RegisterAssetTypePreviewComponent(UClass* AssetType, UPrimitiveComponent* InComponent);
    
private:
    UFUNCTION(BlueprintCallable)
    void ActivateStaticMeshPreview(UPrimitiveComponent* Primitive, UObject* Asset);
    
    UFUNCTION(BlueprintCallable)
    void ActivateNiagaraSystemPreview(UPrimitiveComponent* Primitive, UObject* Asset);
    
};

