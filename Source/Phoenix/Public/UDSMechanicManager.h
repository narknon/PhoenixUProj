#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UDSMechanicManager.generated.h"

class UUDSManager;

UCLASS(Blueprintable)
class UUDSMechanicManager : public UObject {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UUDSManager* UDSManager;
    
public:
    UUDSMechanicManager();
};

