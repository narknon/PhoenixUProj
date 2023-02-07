#pragma once
#include "CoreMinimal.h"
#include "SceneRigObjectActionState.h"
#include "SceneActionState_MimicActor.generated.h"

class USkeletalMeshComponent;

UCLASS(Blueprintable)
class SCENERIG_API USceneActionState_MimicActor : public USceneRigObjectActionState {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USkeletalMeshComponent* MeshToModify;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USkeletalMeshComponent* MeshToMimic;
    
public:
    USceneActionState_MimicActor();
};

