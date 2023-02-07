#pragma once
#include "CoreMinimal.h"
#include "ECameraStackResetType.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "SceneRigActionBase.h"
#include "SceneAction_CameraReset.generated.h"

class UTransformProvider;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_CameraReset : public USceneRigActionBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ECameraStackResetType ResetType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTransformProvider* ResetLookAtLocation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRotator FixedArmRotationValue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D RotationOffset;
    
    USceneAction_CameraReset();
};

