#pragma once
#include "CoreMinimal.h"
#include "AblStartPositionGetter.h"
#include "AblStartPositionGetter_TimeMatch.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblStartPositionGetter_TimeMatch : public UAblStartPositionGetter {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOnlyTimeMatchIfAnimInstanceAgrees;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSetFixedDirectionForTurnAssist;
    
public:
    UAblStartPositionGetter_TimeMatch();
};

