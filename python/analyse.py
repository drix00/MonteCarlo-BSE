import sys
import os

import pandas as pd
import matplotlib.pyplot as plt


def analyse(path):
    print(path)
    for file_name in os.listdir(path):
        if file_name.startswith("simulate_number_trajectories_repetitions_"):
            file_path = os.path.join(path, file_name)
            pd_data = pd.read_csv(file_path)

            print(pd_data.head())
            pd_data.columns = [name.strip() for name in pd_data.columns]

            grouped = pd_data["elapse time s"].groupby(pd_data["number trajectories"])
            figure, axes = plt.subplots()
            means = grouped.mean()
            errors = grouped.std()
            print(means.index)
            axes.errorbar(means.index, means.values, errors.values*3, fmt='.')
            axes.set_xlabel("Number of trajectories")
            axes.set_ylabel("Simulation time (s)")
            figure.tight_layout()

            grouped = pd_data["bse"].groupby(pd_data["number trajectories"])
            figure, axes = plt.subplots()
            means = grouped.mean()
            errors = grouped.std()
            print(means.index)
            axes.errorbar(means.index, means.values, errors.values*3, fmt='.')
            axes.set_xlabel("Number of trajectories")
            axes.set_ylabel(r"BSE coefficient $\eta$")
            axes.set_xscale('log')
            figure.tight_layout()

        elif file_name.startswith("simulate_densities_"):
            file_path = os.path.join(path, file_name)
            pd_data = pd.read_csv(file_path)

            print(pd_data.head())
            pd_data.columns = [name.strip() for name in pd_data.columns]

            grouped = pd_data["elapse time s"].groupby(pd_data["density (g/cm3)"])
            figure, axes = plt.subplots()
            means = grouped.mean()
            errors = grouped.std()
            print(means.index)
            axes.errorbar(means.index, means.values, errors.values*3, fmt='.')
            axes.set_xlabel("Density (g/cm3)")
            axes.set_ylabel("Simulation time (s)")
            figure.tight_layout()

            grouped = pd_data["bse"].groupby(pd_data["density (g/cm3)"])
            figure, axes = plt.subplots()
            means = grouped.mean()
            errors = grouped.std()
            print(means.index)
            axes.errorbar(means.index, means.values, errors.values*3, fmt='.')
            axes.set_xlabel("Density (g/cm3)")
            axes.set_ylabel(r"BSE coefficient $\eta$")
            # axes.set_xscale('log')
            axes.set_ylim((0.32, 0.34))
            figure.tight_layout()

        elif file_name.startswith("simulate_atomic_numbers_"):
            file_path = os.path.join(path, file_name)
            pd_data = pd.read_csv(file_path)

            print(pd_data.head())
            pd_data.columns = [name.strip() for name in pd_data.columns]

            figure, axes = plt.subplots()
            axes.plot(pd_data["atomic number"], pd_data["elapse time s"], '.')
            axes.set_xlabel("Atomic number")
            axes.set_ylabel("Simulation time (s)")
            figure.tight_layout()

            figure, axes = plt.subplots()
            axes.errorbar(pd_data["atomic number"], pd_data["bse"], pd_data["bse std"]*3, fmt='.')
            axes.set_xlabel("Atomic number")
            axes.set_ylabel(r"BSE coefficient $\eta$")
            figure.tight_layout()

        elif file_name.startswith("simulate_elements_energies_"):
            file_path = os.path.join(path, file_name)
            pd_data = pd.read_csv(file_path)

            print(pd_data.head())
            pd_data.columns = [name.strip() for name in pd_data.columns]

            figure, axes = plt.subplots()
            for name, group in pd_data.groupby(pd_data["atomic number"]):
                axes.plot(group["initial energy eV"], group["elapse time s"], '-', label=name)

            axes.set_xlabel("Initial energy eV")
            axes.set_ylabel("Simulation time (s)")
            axes.legend()
            figure.tight_layout()

            figure, axes = plt.subplots()
            for name, group in pd_data.groupby(pd_data["atomic number"]):
                axes.errorbar(group["initial energy eV"], group["bse"], group["bse std"]*3, fmt='-', label=name)

            axes.set_xlabel("Initial energy eV")
            axes.set_ylabel(r"BSE coefficient $\eta$")
            axes.legend()
            figure.tight_layout()

        elif file_name.startswith("simulate_thickness_"):
            file_path = os.path.join(path, file_name)
            pd_data = pd.read_csv(file_path)

            print(pd_data.head())
            pd_data.columns = [name.strip() for name in pd_data.columns]

            figure, axes = plt.subplots()
            for name, group in pd_data.groupby(pd_data["atomic number"]):
                axes.plot(group["thickness (nm)"], group["elapse time s"], '-', label=name)

            axes.set_xlabel("Thickness (nm)")
            axes.set_ylabel("Simulation time (s)")
            axes.legend()
            figure.tight_layout()

            figure, axes = plt.subplots()
            for name, group in pd_data.groupby(pd_data["atomic number"]):
                axes.errorbar(group["thickness (nm)"], group["bse"], group["bse std"]*3, fmt='-', label=name)

            axes.set_xlabel("Thickness (nm)")
            axes.set_ylabel(r"BSE coefficient $\eta$")
            axes.legend()
            figure.tight_layout()

            figure, axes = plt.subplots()
            for name, group in pd_data.groupby(pd_data["atomic number"]):
                axes.errorbar(group["thickness (nm)"], group["te"], group["te std"]*3, fmt='-')

            axes.set_xlabel("Thickness (nm)")
            axes.set_ylabel(r"TE coefficient")
            axes.legend()
            figure.tight_layout()


if __name__ == '__main__':
    if len(sys.argv) > 1:
        analyse(sys.argv[1])

        plt.show()
