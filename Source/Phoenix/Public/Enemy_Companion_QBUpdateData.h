#pragma once
#include "CoreMinimal.h"
#include "Enemy_QBUpdateData.h"
#include "Enemy_Companion_QBUpdateData.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UEnemy_Companion_QBUpdateData : public UEnemy_QBUpdateData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PlayerTetherDist;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PlayerInsideDist;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float StrafeDist;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinDistFromTarget;
    
    UEnemy_Companion_QBUpdateData();
};

