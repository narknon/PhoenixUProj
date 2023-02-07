#pragma once
#include "CoreMinimal.h"
#include "MoveRequestProvider.h"
#include "UObject/NoExportTypes.h"
#include "SceneRigObjectActionState.h"
#include "SceneActionState_StitchTester.generated.h"

class AActor;
class USceneActionState_Transform;

UCLASS(Blueprintable)
class SCENERIG_API USceneActionState_StitchTester : public USceneRigObjectActionState, public IMoveRequestProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTransform CurrentTransform;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* Actor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USceneActionState_Transform* TransformActionState;
    
public:
    USceneActionState_StitchTester();
    
    // Fix for true pure virtual functions not being implemented
};

