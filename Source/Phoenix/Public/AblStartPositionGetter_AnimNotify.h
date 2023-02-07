#pragma once
#include "CoreMinimal.h"
#include "AblStartPositionGetter.h"
#include "AblStartPositionGetter_AnimNotify.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblStartPositionGetter_AnimNotify : public UAblStartPositionGetter {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName AnimNotifyEventName;
    
public:
    UAblStartPositionGetter_AnimNotify();
};

