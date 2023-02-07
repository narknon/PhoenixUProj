#pragma once
#include "CoreMinimal.h"
#include "BlendSpaceInputProvider.h"
#include "BlendSpaceInput_WandLink.generated.h"

class UActorProvider;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UBlendSpaceInput_WandLink : public UBlendSpaceInputProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UActorProvider* Provider;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bPlayer;
    
    UBlendSpaceInput_WandLink();
};

