#pragma once
#include "CoreMinimal.h"
#include "Enemy_QBUpdateData.h"
#include "Enemy_TombProtector_QBUpdateData.generated.h"

class UEnemy_TombProtector_QBUpdateDataAsset;

UCLASS(Blueprintable, EditInlineNew)
class UEnemy_TombProtector_QBUpdateData : public UEnemy_QBUpdateData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UEnemy_TombProtector_QBUpdateDataAsset* DataAsset;
    
    UEnemy_TombProtector_QBUpdateData();
};

