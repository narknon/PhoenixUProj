#pragma once
#include "CoreMinimal.h"
#include "BTT_Camera_BlendToStackBase.h"
#include "BTT_Camera_BlendToStack.generated.h"

UCLASS(Blueprintable)
class UBTT_Camera_BlendToStack : public UBTT_Camera_BlendToStackBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BlendInDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BlendOutDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bLazyBlendOut;
    
    UBTT_Camera_BlendToStack();
};

