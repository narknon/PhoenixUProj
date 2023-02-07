#pragma once
#include "CoreMinimal.h"
#include "ActorProvider.h"
#include "Actor_StageRoot.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class SCENERIG_API UActor_StageRoot : public UActorProvider {
    GENERATED_BODY()
public:
    UActor_StageRoot();
};

