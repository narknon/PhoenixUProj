#pragma once
#include "CoreMinimal.h"
#include "SceneRigActorMemberReference.generated.h"

USTRUCT(BlueprintType)
struct SCENERIG_API FSceneRigActorMemberReference {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName MemberName;
    
    FSceneRigActorMemberReference();
};

