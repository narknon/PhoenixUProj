#pragma once
#include "CoreMinimal.h"
#include "ActorProvider.h"
#include "SceneRigActorMemberReference.h"
#include "Templates/SubclassOf.h"
#include "Actor_SceneRigActorMember.generated.h"

class ASceneRigActor;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class SCENERIG_API UActor_SceneRigActorMember : public UActorProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<ASceneRigActor> ActorClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigActorMemberReference Member;
    
    UActor_SceneRigActorMember();
};

