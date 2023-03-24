#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "EPSOCachingLevelMode.h"
#include "PSOCachingLevelController.generated.h"

UCLASS(Blueprintable)
class PSOCACHING_API APSOCachingLevelController : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CameraRotationSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UClass*> PreviewedAssetTypes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSet<FSoftObjectPath> AssetsToIgnore;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSoftObjectPath> PredefinedAssetsForPreview;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 DebugFastAssetsCount;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    EPSOCachingLevelMode Mode;
    
    APSOCachingLevelController(const FObjectInitializer& ObjectInitializer);
};

