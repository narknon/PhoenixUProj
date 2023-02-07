#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SceneRigObjectActionState.h"
#include "SceneActionState_Attach.generated.h"

class UTransformProvider;

UCLASS(Blueprintable)
class SCENERIG_API USceneActionState_Attach : public USceneRigObjectActionState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool PlacementIsMoving;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool PlacementIsValid;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTransform InitialPlacementTransform;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTransformProvider* PlacementProvider;
    
    USceneActionState_Attach();
};

