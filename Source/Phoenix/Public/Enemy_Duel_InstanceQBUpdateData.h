#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Enemy_InstanceQBUpdateData.h"
#include "Enemy_Duel_InstanceQBUpdateData.generated.h"

UCLASS(Blueprintable)
class UEnemy_Duel_InstanceQBUpdateData : public UEnemy_InstanceQBUpdateData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector EndPoint1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector EndPoint2;
    
    UEnemy_Duel_InstanceQBUpdateData();
};

