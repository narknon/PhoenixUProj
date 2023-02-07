#pragma once
#include "CoreMinimal.h"
#include "Curves/CurveFloat.h"
#include "SceneRigObjectActionBase.h"
#include "SceneAction_WaterRipple.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_WaterRipple : public USceneRigObjectActionBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FName> BonesToTrack;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Radius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float IntensityMultiplier;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName SocketName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRuntimeFloatCurve Intensity;
    
    USceneAction_WaterRipple();
};

