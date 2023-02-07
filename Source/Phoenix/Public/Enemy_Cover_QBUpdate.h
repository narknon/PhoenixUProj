#pragma once
#include "CoreMinimal.h"
#include "Enemy_QBUpdate.h"
#include "Enemy_Cover_QBUpdate.generated.h"

class UEnvQuery;

UCLASS(Blueprintable)
class UEnemy_Cover_QBUpdate : public UEnemy_QBUpdate {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UEnvQuery* CoverQuery;
    
    UEnemy_Cover_QBUpdate();
};

