#pragma once
#include "CoreMinimal.h"
#include "Enemy_QBUpdateData.h"
#include "Enemy_Close_QBUpdateData.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UEnemy_Close_QBUpdateData : public UEnemy_QBUpdateData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float StartDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float EndDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bStopWhenEnding;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOutCanCloseIfInRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Timeout;
    
    UEnemy_Close_QBUpdateData();
};

