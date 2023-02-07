#pragma once
#include "CoreMinimal.h"
#include "AblStartPositionGetter.h"
#include "ablStartPositionGetter_TrollSwing.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UablStartPositionGetter_TrollSwing : public UAblStartPositionGetter {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ForehandStartTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BackhandStartTime;
    
public:
    UablStartPositionGetter_TrollSwing();
};

