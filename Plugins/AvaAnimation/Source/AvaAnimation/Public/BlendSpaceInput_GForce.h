#pragma once
#include "CoreMinimal.h"
#include "BlendSpaceInputProvider.h"
#include "EAxisMapping.h"
#include "BlendSpaceInput_GForce.generated.h"

class UActorProvider;
class UFloatProvider;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class AVAANIMATION_API UBlendSpaceInput_GForce : public UBlendSpaceInputProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UActorProvider* ActorToGetAccelerationFrom;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UFloatProvider* Alpha;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EAxisMapping HorizontalAxis;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EAxisMapping VerticalAxis;
    
    UBlendSpaceInput_GForce();
};

