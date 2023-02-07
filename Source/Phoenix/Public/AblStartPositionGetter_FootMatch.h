#pragma once
#include "CoreMinimal.h"
#include "AblStartPositionGetter.h"
#include "UObject/NoExportTypes.h"
#include "AblStartPositionGetter_FootMatch.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblStartPositionGetter_FootMatch : public UAblStartPositionGetter {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector FootPositionWeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector FootVelocityWeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinStartTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxStartTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SourceTimeOffset;
    
public:
    UAblStartPositionGetter_FootMatch();
};

