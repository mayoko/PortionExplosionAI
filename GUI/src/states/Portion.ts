export enum PortionType {
    PORTION_OF_WISDOM = 'Portion of Wisdom',
    PORTION_OF_MAGNETICAL_ATTRACTION = 'Portion of Magnetical Attraction',
    ABYSSAL_DRAFT = 'Abyssal Draft',
    BALM_OF_UTTERMOST_STICKNESS = 'Balm of Uttermost Stickiness',
    ELIXIR_OF_BLIND_LOVE = 'Elixir of Blind Love',
    PORTION_OF_PRISMATIC_JOY = 'Portion of Prismatic Joy',
    SANDS_OF_TIME = 'Sands of Time',
    FILTER_OF_LAVAMANCING = 'Filter of Lavamancing',
    NONE = 'NONE',
}

export const stringToPortionType = (typeString: string): PortionType => {
    // const matchedPortionType = Object.entries(PortionType)
    //     .filter(entry => entry[1] === typeString)
    //     .map(entry => entry[1]);
    const matchedPortionType = Object.values(PortionType).filter(
        value => value === typeString,
    );

    return matchedPortionType.length > 0
        ? matchedPortionType[0]
        : PortionType.NONE;
};

export default interface Portion {
    type: PortionType;
    count: number;
}
