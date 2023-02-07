#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "BlendSpaceInputProvider.h"
#include "BlendSpaceInput_Direct.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class AVAANIMATION_API UBlendSpaceInput_Direct : public UBlendSpaceInputProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector Parameters;
    
    UBlendSpaceInput_Direct();
};

