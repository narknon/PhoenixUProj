#pragma once
#include "CoreMinimal.h"
#include "ActorProvider.h"
#include "WorldActorReference.h"
#include "Actor_WorldReference.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class SCENERIG_API UActor_WorldReference : public UActorProvider {
    GENERATED_BODY()
public:
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FWorldActorReference ActorReference;
    
    UActor_WorldReference();
};

