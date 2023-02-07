#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ColorProvider.h"
#include "Color_Direct.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class AVAANIMATION_API UColor_Direct : public UColorProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor Value;
    
    UColor_Direct();
};

