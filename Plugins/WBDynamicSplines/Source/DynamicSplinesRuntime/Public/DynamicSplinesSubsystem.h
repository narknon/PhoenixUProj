#pragma once
#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "DynamicSplinesSubsystem.generated.h"

UCLASS(Blueprintable)
class DYNAMICSPLINESRUNTIME_API UDynamicSplinesSubsystem : public UWorldSubsystem {
    GENERATED_BODY()
public:
    UDynamicSplinesSubsystem();
};

