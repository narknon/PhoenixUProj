#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UDSLocationManager.generated.h"

class UUDSManager;

UCLASS(Blueprintable)
class UUDSLocationManager : public UObject {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UUDSManager* UDSManager;
    
public:
    UUDSLocationManager();
};

