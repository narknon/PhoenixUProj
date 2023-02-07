#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "TimeRigNamedSymbol.h"
#include "TimeRigElement.generated.h"

class UTimeRigElement;

UCLASS(Blueprintable)
class TIMERIG_API UTimeRigElement : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool Enabled;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UTimeRigElement* ParentElement;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName UserName;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FTimeRigNamedSymbol> NamedSymbols;
    
public:
    UTimeRigElement();
};

