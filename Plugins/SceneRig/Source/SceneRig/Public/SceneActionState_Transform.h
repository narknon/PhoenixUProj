#pragma once
#include "CoreMinimal.h"
#include "AnimDebugInfo.h"
#include "MoveRequestProvider.h"
#include "UObject/NoExportTypes.h"
#include "SceneActionState_AnimateCurves.h"
#include "SceneActionState_Transform.generated.h"

UCLASS(Blueprintable)
class SCENERIG_API USceneActionState_Transform : public USceneActionState_AnimateCurves, public IMoveRequestProvider, public IAnimDebugInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IsPossiblyRegistered;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IsRegistered;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTransform CurrentTransform;
    
    USceneActionState_Transform();
    
    // Fix for true pure virtual functions not being implemented
};

