#pragma once
#include "CoreMinimal.h"
#include "AblStartPositionGetter.h"
#include "AblStartPositionGetter_Protego.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblStartPositionGetter_Protego : public UAblStartPositionGetter {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ImpactFrame;
    
public:
    UAblStartPositionGetter_Protego();
};

