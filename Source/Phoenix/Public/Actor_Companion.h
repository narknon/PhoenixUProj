#pragma once
#include "CoreMinimal.h"
#include "ActorProvider.h"
#include "Actor_Companion.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UActor_Companion : public UActorProvider {
    GENERATED_BODY()
public:
    UActor_Companion();
};

