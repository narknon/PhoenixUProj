#pragma once
#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "ETrollSwingDirection.h"
#include "TrollSwingDirectionAnimNotify.generated.h"

UCLASS(Blueprintable, CollapseCategories)
class UTrollSwingDirectionAnimNotify : public UAnimNotify {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ETrollSwingDirection SwingDirection;
    
    UTrollSwingDirectionAnimNotify();
};

