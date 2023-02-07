#pragma once
#include "CoreMinimal.h"
#include "ActorProvider.h"
#include "Actor_TransfigurationObject.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class PHOENIX_API UActor_TransfigurationObject : public UActorProvider {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    uint32 TransfigurationUID;
    
    UActor_TransfigurationObject();
};

