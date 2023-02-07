#pragma once
#include "CoreMinimal.h"
#include "SceneAction_HermesMessageAdvancedStartEnd.h"
#include "SceneAction_HermesMessageAdvancedStartEndToActor.generated.h"

class UActorProvider;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_HermesMessageAdvancedStartEndToActor : public USceneAction_HermesMessageAdvancedStartEnd {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UActorProvider* ToActor;
    
    USceneAction_HermesMessageAdvancedStartEndToActor();
};

