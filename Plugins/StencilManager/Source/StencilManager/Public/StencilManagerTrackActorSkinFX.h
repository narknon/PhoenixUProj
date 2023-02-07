#pragma once
#include "CoreMinimal.h"
#include "StencilManagerSkinFX.h"
#include "StencilManagerTrackActor.h"
#include "StencilManagerTrackActorSkinFX.generated.h"

class USkinFXComponent;

USTRUCT(BlueprintType)
struct FStencilManagerTrackActorSkinFX : public FStencilManagerTrackActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FStencilManagerSkinFX SkinFX;
    
    UPROPERTY(EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<USkinFXComponent> SkinFXComponent;
    
    STENCILMANAGER_API FStencilManagerTrackActorSkinFX();
};

