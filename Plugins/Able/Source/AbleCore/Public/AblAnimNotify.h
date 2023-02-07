#pragma once
#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "AblAnimNotify.generated.h"

UCLASS(Blueprintable, CollapseCategories)
class ABLECORE_API UAblAnimNotify : public UAnimNotify {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName EventName;
    
    UAblAnimNotify();
};

