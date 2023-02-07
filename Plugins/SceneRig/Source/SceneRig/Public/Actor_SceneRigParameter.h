#pragma once
#include "CoreMinimal.h"
#include "ActorProvider.h"
#include "SceneRigParameterBinding_Object.h"
#include "Actor_SceneRigParameter.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class SCENERIG_API UActor_SceneRigParameter : public UActorProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSceneRigParameterBinding_Object BoundParameter;
    
    UActor_SceneRigParameter();
};

