#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "DynamicDB_Interface.generated.h"

UINTERFACE(MinimalAPI)
class UDynamicDB_Interface : public UInterface {
    GENERATED_BODY()
};

class IDynamicDB_Interface : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION()
    virtual void SetupDBQueries() PURE_VIRTUAL(SetupDBQueries,);
    
};

